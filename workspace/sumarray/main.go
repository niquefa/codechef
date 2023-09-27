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
func printSolution(answer []int64) {
	for i, v := range answer {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(v)
	}
	fmt.Println()
}
func solve() {
	var totalNumberInAnswer, desiredSum int64 //totalNumberInAnswer is even always
	scan(&totalNumberInAnswer, &desiredSum)

	totalEvenNumbersAllowed := totalNumberInAnswer / 2
	totalOddNumbersAllowed := totalNumberInAnswer / 2
	//debug(totalEvenNumbersAllowed, totalOddNumbersAllowed)
	minSumPossible := totalOddNumbersAllowed + totalEvenNumbersAllowed*2
	maxSumPossible := totalOddNumbersAllowed*99999 + 100000*totalEvenNumbersAllowed
	//debug(totalNumberInAnswer, desiredSum, "minSumPossible", minSumPossible, "maxSumPossible", maxSumPossible)
	if desiredSum < minSumPossible || desiredSum > maxSumPossible {
		fmt.Println(-1)
		return
	}
	if desiredSum%2 == 0 && totalOddNumbersAllowed%2 != 0 {
		fmt.Println(-1)
		return
	}
	if desiredSum%2 == 1 && totalOddNumbersAllowed%2 == 0 {
		fmt.Println(-1)
		return
	}
	if totalNumberInAnswer == 2 {
		if desiredSum%2 == 0 {
			fmt.Println(desiredSum-2, 2)
		} else {
			fmt.Println(desiredSum-1, 1)
		}
		return
	}

	answer := make([]int64, totalOddNumbersAllowed*2)
	for i := int64(0); i < totalOddNumbersAllowed; i++ {
		answer[i] = 1
		answer[i+totalOddNumbersAllowed] = 2
	}
	//debug(answer)
	desiredSum -= minSumPossible
	if desiredSum == 0 {
		printSolution(answer)
		return
	}
	if desiredSum%2 == 1 {
		fmt.Println(-1)
		return
	}
	var additionToAll int64 = desiredSum / totalNumberInAnswer
	if additionToAll%2 == 1 {
		additionToAll--
	}
	//debug("additionToAll", additionToAll)
	if additionToAll == 0 {
		additionToAll = 2
	}
	for i := 0; i < len(answer); i++ {
		answer[i] += additionToAll
		desiredSum -= additionToAll
		if desiredSum == 0 {
			printSolution(answer)
			return
		}
	}
	for i := 0; i < len(answer); i++ {
		answer[i] += 2
		desiredSum -= 2
		if desiredSum == 0 {
			printSolution(answer)
			return
		}
	}
	fmt.Println(-1)
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
