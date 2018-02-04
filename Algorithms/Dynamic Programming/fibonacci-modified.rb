#!/bin/ruby

t1,t2,n = gets.strip.split.map(&:to_i)

arr = [t1,t2]

until arr.length > n
   arr << arr[-1]**2 + arr[-2] 
end

puts arr[n-1]

