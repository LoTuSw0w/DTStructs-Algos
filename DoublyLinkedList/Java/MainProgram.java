/**
 * Hello
 */
public class MainProgram {
    public static void main(String[] args) {
        DoublyLinkedList myFirstList = new DoublyLinkedList(new DLL_Node(1));
        myFirstList.AddNextNode(new DLL_Node(2));
        myFirstList.AddNextNode(new DLL_Node(3));
        myFirstList.AddNextNode(new DLL_Node(4));
        myFirstList.AddNextNode(new DLL_Node(5));
        myFirstList.AddNextNode(new DLL_Node(6));
        myFirstList.AddNodeToStart(new DLL_Node(0));

        System.out.println(myFirstList.GetLastNodeData());
        System.out.println(myFirstList.head.Data);
        System.out.println(myFirstList.head.next.Data);
    }

}

class DLL_Node {
    public int Data;
    public DLL_Node next;
    public DLL_Node previous;

    public DLL_Node(int data) {
        this.Data = data;
        this.next = null;
        this.previous = null;
    }
}

class DoublyLinkedList {
    public DLL_Node head;

    public DoublyLinkedList(DLL_Node head) {
        this.head = head;
    }

    public void AddNextNode(DLL_Node nextNode) {
        if (head == null) {
            head = nextNode;
        } else {
            DLL_Node current = head;
            while (current.next != null) {
                current = current.next;
            }
            current.next = nextNode;
            nextNode.previous = current;
        }
    }

    public void AddNodeToStart(DLL_Node newHead) {
        if (head == null) {
            head = newHead;
        } else {
            DLL_Node temp = head;
            newHead.next = temp;
            temp.previous = newHead;
            head = newHead;
        }

    }

    public int GetLastNodeData() {
        DLL_Node current = head;
        while (current.next != null) {
            current = current.next;
        }
        return current.Data;
    }
}
