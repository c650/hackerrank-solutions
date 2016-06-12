#!/bin/ruby

n = gets.strip.to_i
a = Array.new(n)
for a_i in (0...n)
    a_t = gets.strip
    a[a_i] = a_t.split(' ').map(&:to_i)
end
primary = 0
secondary = 0
for i in (0...n)
    primary += a[i][i]
    secondary += a[i][n-i-1]
end
puts (primary - secondary).abs

