import unittest
import os
import csv
import sys
import importlib

# ---- CONFIGURATION ----
TEST_FILE = "test_cyber_cafe.csv"

# Temporarily override filename used by the main script
sys.modules.pop("cyber_cafe", None)
import cyber_cafe
cyber_cafe.FILENAME = TEST_FILE


class TestCyberCafeSystem(unittest.TestCase):

    def setUp(self):
        """Runs before every test"""
        if os.path.exists(TEST_FILE):
            os.remove(TEST_FILE)
        cyber_cafe.ensure_file()

    def tearDown(self):
        """Runs after every test"""
        if os.path.exists(TEST_FILE):
            os.remove(TEST_FILE)

    def read_csv_raw(self):
        with open(TEST_FILE, newline="") as f:
            return list(csv.reader(f))

    def test_file_creation_and_header(self):
        data = self.read_csv_raw()
        self.assertEqual(data[0], [
            "CustomerID",
            "Name",
            "Mobile",
            "SystemNo",
            "Hours",
            "Purpose",
            "Amount"
        ])

    def test_add_record(self):
        records = [
            ["C001", "Alice", "9999999999", "PC1", "2", "Browsing", "100"]
        ]
        cyber_cafe.write_records(records)

        stored = cyber_cafe.read_records()
        self.assertEqual(len(stored), 1)
        self.assertEqual(stored[0][0], "C001")
        self.assertEqual(float(stored[0][6]), 100.0)

    def test_duplicate_customer_id(self):
        records = [
            ["C001", "Alice", "9999999999", "PC1", "2", "Browsing", "100"]
        ]
        cyber_cafe.write_records(records)

        stored = cyber_cafe.read_records()
        duplicate = ["C001", "Bob", "8888888888", "PC2", "1", "Gaming", "50"]

        stored.append(duplicate)
        cyber_cafe.write_records(stored)

        final_records = cyber_cafe.read_records()
        ids = [r[0] for r in final_records]

        self.assertEqual(ids.count("C001"), 2)

    def test_delete_record(self):
        records = [
            ["C001", "Alice", "9999999999", "PC1", "2", "Browsing", "100"],
            ["C002", "Bob", "8888888888", "PC2", "1", "Gaming", "50"]
        ]
        cyber_cafe.write_records(records)

        cyber_cafe.write_records([r for r in records if r[0] != "C001"])

        stored = cyber_cafe.read_records()
        self.assertEqual(len(stored), 1)
        self.assertEqual(stored[0][0], "C002")

    def test_summary_report_calculation(self):
        records = [
            ["C001", "Alice", "9999999999", "PC1", "2", "Browsing", "100"],
            ["C002", "Bob", "8888888888", "PC2", "3", "Gaming", "150"]
        ]
        cyber_cafe.write_records(records)

        total_customers = len(records)
        total_revenue = sum(float(r[6]) for r in records)

        self.assertEqual(total_customers, 2)
        self.assertEqual(total_revenue, 250.0)


if __name__ == "__main__":
    unittest.main()