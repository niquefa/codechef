package main

import (
	"bufio"
	"fmt"
	"os"
	"time"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func flush()                            { out.Flush() }
func scan(a ...interface{})             { fmt.Fscan(in, a...) }
func printf(f string, a ...interface{}) { fmt.Fprintf(out, f, a...) }
func debug(a ...interface{})            { fmt.Fprintln(os.Stderr, a...) }
func assert(f bool) {
	if !f {
		panic("gg Rafa, something went wrong!")
	}
}

// ----------------------------- TEMPLATE END ----------------------------------
type Node struct {
	value string
	next  *Node
}

type LinkedList struct {
	head *Node
	tail *Node
}

func (list *LinkedList) Append(value string) {
	newNode := &Node{value: value}
	if list.head == nil {
		list.head = newNode
		list.tail = newNode
		return
	}
	list.tail.next = newNode
	list.tail = newNode
}

func (list *LinkedList) Display() {
	current := list.head
	if current == nil {
		return
	}
	fmt.Print(current.value)
	current = current.next
	for current != nil {
		fmt.Print(" ")
		fmt.Print(current.value)
		current = current.next

	}
	fmt.Println()
}
func (list *LinkedList) RemoveDuplicates() {
	if list.head == nil {
		return
	}

	valueMap := make(map[string]bool)
	current := list.head
	valueMap[current.value] = true

	for current.next != nil {
		if valueMap[current.next.value] {
			current.next = current.next.next
			if current.next == nil {
				list.tail = current
			}
		} else {
			valueMap[current.next.value] = true
			current = current.next
		}
	}
}
func solve() {
	var n int
	scan(&n)
	b := &LinkedList{}
	for i := 0; i < n; i++ {
		var x string
		scan(&x)
		b.Append(x)
	}
	b.RemoveDuplicates()
	b.Display()
}

func main() {
	startTime := time.Now()

	defer flush()

	var ntc int
	scan(&ntc)
	for t := 0; t < ntc; t++ {

		solve()

	}

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
