function CoA()
	while true do
		print("A")
		coroutine.yield()
		print("B")
		coroutine.yield()
		print("C")
		coroutine.yield()
	end
end

function CoB()
	while true do
		print("1")
		coroutine.yield()
		print("2")
		coroutine.yield()
		print("3")
		coroutine.yield()
	end
end

local a = coroutine.create(CoA)
local b = coroutine.create(CoB)

local prev = os.clock()
for i = 1, 20 do
	while os.clock() < prev + 0.1 do
	end
	prev = os.clock()
	coroutine.resume(a)
	coroutine.resume(b)
end

