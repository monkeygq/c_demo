File.open("computation-intensive.data", "r") do |file|
	while line = file.gets
		sample_period = line.split("=").last.strip
		line = file.gets
		line = file.gets
		sample_count = line.split("(").last.split.first
		puts "#{sample_period} #{sample_count}"
	end
end
