local ledit = require "leditlib"

function main()
   ledit.enable_raw_mode()
   while true do
      local s = io.read()
      if s == nil or s == 'q' then break end
      io.write(s)
   end
end

main()
