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

type TreeNode struct {
	value int64
	left  *TreeNode
	right *TreeNode
}

func insert(root *TreeNode, value int64) *TreeNode {
	if root == nil {
		return &TreeNode{value: value}
	}

	if value < root.value {
		root.left = insert(root.left, value)
	} else {
		root.right = insert(root.right, value)
	}

	return root
}

func printLeaves(root *TreeNode) {
	if root == nil {
		return
	}

	if root.left == nil && root.right == nil {
		printf("%d ", root.value)
		return
	}

	printLeaves(root.left)
	printLeaves(root.right)
}

func solve() {
	var n int
	scan(&n)

	var root *TreeNode
	//debug(n)
	for i := 0; i < n; i++ {
		var x int64
		//debug(i, x)
		scan(&x)
		root = insert(root, x)
	}

	printLeaves(root)
	printf("\n")
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
