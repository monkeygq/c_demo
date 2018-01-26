hash = Hash.new(0)
output = File.new("#{ARGV.first}.available.avg", "w")
File.open(ARGV.first, "r") do |file|
	while line = file.gets
		sample_period = line.split("=").last.strip
		line = file.gets
		line = file.gets
		sample_count = line.split("(").last.split.first
		#output.puts "#{sample_period} #{sample_count}"
		hash[sample_period] += sample_count.to_i
	end
end

hash.each do |k, v|
	sample_count_avg = v / 4
	output.puts "#{k} #{sample_count_avg}"
end
output.close
