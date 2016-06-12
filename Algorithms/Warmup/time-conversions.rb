#!/bin/ruby

time = gets.strip

if time.include?("AM")
    
    time.gsub!("AM","")
    
    hour = time.split(":").first.to_i
    rest_of_time = time.split(":").last(2)
    
    if hour == 12
        hour = 0
        # put hour twice for 00 instead of 0
        time = "#{hour}#{hour}:#{rest_of_time.join(":")}"
    end
else
    
    time.gsub!("PM","")
    
    unless time.split(":").first == "12" then
        #time.split(":").first = "#{time.split(":").first.to_i + 12}"
        
        hour = time.split(":").first.to_i
        rest_of_time = time.split(":").last(2)
        
        time = "#{hour + 12}:#{rest_of_time.join(":")}"
    end
    
end

puts time
