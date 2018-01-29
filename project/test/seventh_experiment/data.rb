output = File.new("#{ARGV.first}.available", "w")
h = {}
File.open(ARGV.first, "r") do |file|
	while line = file.gets
		size = line.split.first
		rate = line.split.last
		h[size] = [] if h[size].nil?
		h[size] << rate.to_f
		#output.puts "#{sample_period} #{sample_count}"
	end
end
it = [h.keys[0]] + h.keys[1..-1].sort {|x,y| y.to_f <=> x.to_f}

it.each_with_index do |i, index|
	output.puts "#{index + 1} #{h[i].reduce(:+) / h[i].size} #{h[i].max - h[i].min}"
end

output.close
