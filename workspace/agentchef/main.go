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

func solve() {
	var earnPerSellFloat int64
	scan(&earnPerSellFloat)
	earnPerSell := earnPerSellFloat * 100

	answer := (100*5*100 + earnPerSell - 1) / earnPerSell

	fmt.Println(answer)

}

func main() {
	startTime := time.Now()

	defer flush()

	var t int
	scan(&t)
	for i := 0; i < t; i++ {
		solve()
	}

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
