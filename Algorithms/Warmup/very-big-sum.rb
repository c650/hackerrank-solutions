#!/bin/ruby

n = gets.strip.to_i
arr = gets.strip
sum = 0
arr = arr.split(' ').map(&:to_f).map{|x| sum += x}
puts sum.to_i
