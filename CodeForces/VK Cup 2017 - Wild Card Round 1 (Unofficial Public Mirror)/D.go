package main

import (
	"fmt"
	"sort"
)

func main() {
	var N, L, R int
	var A, B [100007]int

	_,_ = fmt.Scanf("%d", &N)
	_,_ = fmt.Scanf("%d", &L)
	_,_ = fmt.Scanf("%d", &R)


	for i:= 0; i < N; i++ {
		fmt.Scanf("%d", &A[i])
	}

	for i:= 0; i < N; i++ {
		fmt.Scanf("%d", &B[i])
	}

	sliceA := make([]int, 0)
	sliceB := make([]int, 0)

	L = L - 1
	R = R - 1

	for i:= L; i <= R; i++ {
		sliceA = append(sliceA, A[i]);
		sliceB = append(sliceB, B[i]);
	}

	sort.Ints(sliceA)
	sort.Ints(sliceB)

	ok := 1

	sliceLen := len(sliceA)

	for i:=0; i< sliceLen; i++ {
		if sliceA[i] != sliceB[i] {
			ok = 0
		}
	}

	for i:=0; i < L; i++ {
		if A[i] != B[i]{
			ok = 0
		}
	}

	for i:=R+1; i<N; i++ {
		if A[i] != B[i] {
			ok = 0
		}
	}

	if ok == 1 {
		fmt.Println("TRUTH\n")
	} else {
		fmt.Println("LIE\n")
	}
}