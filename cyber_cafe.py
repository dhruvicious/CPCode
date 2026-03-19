import csv
import os

FILENAME = "cyber_cafe.csv"
RATE_PER_HOUR = 50


def line():
    print("-" * 60)


def pause():
    input("\nPress Enter to continue...")


def ensure_file():
    if not os.path.exists(FILENAME):
        with open(FILENAME, "w", newline="") as f:
            writer = csv.writer(f)
            writer.writerow([
                "CustomerID",
                "Name",
                "Mobile",
                "SystemNo",
                "Hours",
                "Purpose",
                "Amount"
            ])


def read_records():
    ensure_file()
    records = []

    with open(FILENAME, "r", newline="") as f:
        reader = csv.reader(f)
        header = next(reader, None)

        for row in reader:
            if row:
                records.append(row)

    return records

def write_records(records):
    with open(FILENAME, "w", newline="") as f:
        writer = csv.writer(f)

        writer.writerow([
            "CustomerID",
            "Name",
            "Mobile",
            "SystemNo",
            "Hours",
            "Purpose",
            "Amount"
        ])

        writer.writerows(records)


def add_record():
    ensure_file()

    print("ADD NEW CUSTOMER RECORD")

    cid = input("Enter Customer ID: ").upper()
    name = input("Enter Customer Name: ")
    mobile = input("Enter Mobile Number: ")
    system = input("Enter System Number: ").upper()
    hours = float(input("Enter Usage Hours: "))
    purpose = input("Enter Purpose: ")

    amount = hours * RATE_PER_HOUR

    records = read_records()

    for r in records:
        if r[0] == cid:
            print("Customer ID already exists.")
            return

    records.append([
        cid,
        name,
        mobile,
        system,
        str(hours),
        purpose,
        str(amount)
    ])

    write_records(records)

    print("Record added successfully.")
    print("Bill Amount: ₹", amount)

def display_records():
    records = read_records()

    if not records:
        print("No records found.")
        return

    print("-" * 80)
    print("ID\tName\tMobile\t\tSystem\tHours\tPurpose\t\tAmount")
    print("-" * 80)

    for r in records:
        print(
            r[0], "\t",
            r[1], "\t",
            r[2], "\t",
            r[3], "\t",
            r[4], "\t",
            r[5], "\t",
            r[6]
        )

    print("-" * 80)

def search_record():
    records = read_records()

    cid = input("Enter Customer ID to search: ").upper()

    for r in records:
        if r[0] == cid:
            print("Record Found:")
            print(
                "Customer ID :", r[0], "\n"
                "Name        :", r[1], "\n"
                "Mobile      :", r[2], "\n"
                "System No   :", r[3], "\n"
                "Hours       :", r[4], "\n"
                "Purpose     :", r[5], "\n"
                "Amount      : ₹", r[6]
            )
            return

    print("Record not found.")

def delete_record():
    records = read_records()

    cid = input("Enter Customer ID to delete: ").upper()

    found = False
    new_records = []

    for r in records:
        if r[0] == cid:
            found = True
        else:
            new_records.append(r)

    if not found:
        print("Record not found.")
        return

    write_records(new_records)
    print("Record deleted successfully.")

def summary_report():
    records = read_records()

    total_customers = len(records)
    total_revenue = sum(float(r[6]) for r in records)

    print("Total Customers:", total_customers)
    print("Total Revenue: ₹", total_revenue)

def main_menu():
    ensure_file()

    while True:
        print("\nNETZONE CYBER CAFÉ MANAGEMENT SYSTEM")
        print("1. Add Record")
        print("2. Display Records")
        print("3. Search Record")
        print("4. Delete Record")
        print("5. Summary Report")
        print("6. Exit")

        choice = input("Enter choice: ")

        if choice == "1":
            add_record()
            pause()

        elif choice == "2":
            display_records()
            pause()

        elif choice == "3":
            search_record()
            pause()

        elif choice == "4":
            delete_record()
            pause()

        elif choice == "5":
            summary_report()
            pause()

        elif choice == "6":
            print("Program ended.")
            break

        else:
            print("Invalid choice.")


main_menu()