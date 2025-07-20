package main

import (
	"fmt"
	"math"
)

func minPackages(n, k int) int {
	minP := math.MaxInt32
	maxI := k
	if n < k {
		maxI = n
	}

	maxCheck := int(math.Sqrt(float64(n))) + 1
	if maxCheck > maxI {
		maxCheck = maxI
	}

	for i := 1; i <= maxCheck; i++ {
		if n % i == 0 {
			if i <= k {
				p := n / i
				if p < minP {
					minP = p
				}
			}
			paired := n / i
			if paired <= k && paired <= maxI {
				p := i
				if p < minP {
					minP = p
				}
			}
		}
	}

	if minP == math.MaxInt32 {
		return n
	}

	return minP
}

func main() {
	var t int
	fmt.Scan(&t)

	for i := 0; i < t; i++ {
		var n, k int
		fmt.Scan(&n, &k)
		fmt.Println(minPackages(n, k))
	}
}
