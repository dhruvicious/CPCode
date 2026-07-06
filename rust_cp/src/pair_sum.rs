pub struct SolutionPairSum;

#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

impl SolutionPairSum {
    pub fn reverse_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut prev = None;
        let mut curr = head;

        while let Some(mut current_node) = curr {
            let next = current_node.next.take();
            current_node.next = prev;

            prev = Some(current_node);

            curr = next;
        }

        prev
    }

    pub fn pair_sum(mut head: Option<Box<ListNode>>) -> i32 {
        let mut len = 0;
        let mut curr = head.as_ref();

        while let Some(node) = curr {
            len += 1;
            curr = node.next.as_ref();
        }

        let mut curr_mut = &mut head;

        for _ in 0..(len / 2) {
            if let Some(node) = curr_mut {
                curr_mut = &mut node.next;
            }
        }

        let second_half = curr_mut.take();
        let mut p2 = Self::reverse_list(second_half);
        let mut p1 = head;

        let mut max_sum = i32::MIN;
        while let (Some(n1), Some(n2)) = (p1.as_ref(), p2.as_ref()) {
            max_sum = max_sum.max(n1.val + n2.val);
            p1 = p1.unwrap().next;
            p2 = p2.unwrap().next;
        }
        max_sum
    }
}
