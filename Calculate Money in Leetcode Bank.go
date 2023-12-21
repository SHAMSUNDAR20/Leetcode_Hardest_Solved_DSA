
package main

func totalMoney(n int) int {
	day := 0
	week := 0
	ans := 0
	add := 0 // Daily income.
	for i := 0; i < n; i += 1 {
		if 0 == day {
			week += 1
			add = week
		}
		ans += add
		day = (day + 1) % 7
		add += 1
	}
	return ans
}