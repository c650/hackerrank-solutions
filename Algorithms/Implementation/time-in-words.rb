#!/bin/ruby

h = gets.strip.to_i
m = gets.strip.to_i

phrases = {
    11 => "eleven",
    12 => "twelve",
    13 => "thirteen",
    14 => "fourteen",
    15 => "fifteen", 
    16 => "sixteen",
    17 => "seventeen",
    18 => "eighteen",
    19 => "nineteen",
    10 => "ten",
    20 => "twenty",
    1 => "one",
    2 => "two",
    3 => "three",
    4 => "four",
    5 => "five",
    6 => "six",
    7 => "seven",
    8 => "eight",
    9 => "nine"
}

if m == 30
    puts "half past #{phrases[h]}"
elsif m == 0
    puts "#{phrases[h]} o' clock"
elsif m == 1
    puts "one minute past #{phrases[h]}"
elsif m % 15 == 0
    if m < 30
        puts "quarter past #{phrases[h]}" 
    else
        puts "quarter to #{phrases[h + 1]}"
    end
elsif m > 30
    if m % 10 == 0
        puts "#{phrases[m]} minutes to #{phrases[h + 1]}" 
    else
        if m > 40
            puts "#{phrases[60 - m]} minutes to #{phrases[h + 1]}"  
        else
            puts "#{phrases[60 - m - (m % 10)]} #{phrases[m % 10]} minutes to #{phrases[h + 1]}"
        end
    end
else
    if m % 10 == 0
        puts "#{phrases[m]}"
    else
       if m < 20
           puts "#{phrases[m]} minutes past #{phrases[h]}" 
       else
           puts "#{phrases[m - (m % 10)]} #{phrases[m % 10]} minutes past #{phrases[h]}"
       end
    end
end