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
h.each do |k, v|
	output.puts "#{k} #{v.reduce(:+) / v.size} #{v.max - v.min}"
end
output.close
