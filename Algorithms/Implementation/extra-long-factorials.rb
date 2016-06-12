#!/bin/ruby

n = gets.strip.to_i

tmp = n - 1

while tmp > 1
    n *= tmp
    tmp -= 1
end

puts n