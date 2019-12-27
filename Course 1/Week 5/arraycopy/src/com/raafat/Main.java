package com.raafat;

public class Main {

    public static void main(String[] args) {
	// write your code here
        Node first = new Node(10);
        Node n1 = new Node(20);
        Node n2 = new Node(30);
        Node n3 = new Node(40);
        first.next = n1;
        n1.next = n2;
        n2.next = n3;
        Node curr = first;
        while (curr != null) {
            System.out.println(curr.data);
            curr = curr.next;


        }
        first = inverse(first);
        curr = first;
        while (curr != null) {
            System.out.println(curr.data);
            curr = curr.next;


        }

    }

    public static Node inverse(Node first) {
        Node temp;
        Node prev;
        Node Next;
        prev = first;
        temp = first.next;
        Next = temp.next;
        first.next = null;
        while (Next != null) {
            temp.next = prev;
            prev = temp;
            temp = Next;
            Next = Next.next;
        }
        temp.next = prev;
        first = temp;
        return first;

    }
}
