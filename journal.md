7/5/26
Time: 1 hour

To start this project off, I created a drawing of how I wanted the alarm clock to look and just what features I wanted in my alarm clock. As it is a Jellycat cake, I wanted to have a cool feature that made the alarm unique. I decided that I wanted the candle on the cake to light up for small timers or when I just want it to (press a button and the light turns on). I think it makes the alarm seem more alive and more fun to work with. I found these tea lights/bulbs that I could use instead of trying to 3d print with translucent filament, which is so expensive:(  - anyways, they have wires at the end, so I think it could be pretty easy to add. 


This is the tea lights/candle lights I was talking about - a little expensive, but cheaper in my opinion and easier to work with :) 
Also, it's quite pretty, honestly

<img width="552" height="404" alt="amazon lights" src="https://github.com/user-attachments/assets/3d13c6a3-b01b-423a-ae95-9068c559ee20" />

My planning drawing: 
<img width="2360" height="1640" alt="planning doc" src="https://github.com/user-attachments/assets/636def55-443d-4316-b5b4-feb176841009" />


Starting with the CAD first:
Time: 3 Hours

I actually started with CAD first because that is just what I'm more familiar with. I've worked with fusion a lot in my school, and I'm also really scared about the electronics, so I'm trying to avoid it right now. I made the base of the cake, which is just one layer of cake, frosting, the legs, and the iconic Jellycat face. I did this mainly just through a lot of sketches and extrusions. It took me a while to create an offset plane for the face and legs, as sketching on a round surface was definitely throwing me off and wasn't extruding properly. 

I made some space for the PCB and wires, but I haven't made the proper place for it yet. I will do that soon, though! I also made a little place for the display to go, though I am a little confused about how that would work when I design my PCB because I need to have strawberries on the top, but also need the display to be on the front side. I might switch it up and make the display on the top of the cake with the strawberries and candle. Maybe this means I can make the face a little bigger :) I also made little holes so that I can connect the top part after I CAD that too. 

<img width="1512" height="875" alt="jellycat cake alarm clock fusion - base" src="https://github.com/user-attachments/assets/6a50384f-bce2-4671-840f-629459c14c4d" />

YAY - I made the top part, though it's not how I really want it. I really wanted it to be more fluffy-looking, but it kinda just looks like a rock. I don't know, but I'll try to figure that out later.


<img width="1510" height="886" alt="jellycat cake alarm clock fusion - top" src="https://github.com/user-attachments/assets/a61ab89b-1c1f-4fe6-8d0e-da7ce9f55ed1" />

This is the full version with both parts connected, but more updates will be added to the CAD later! 

<img width="1514" height="875" alt="jellycat cake alarm clock fusion - full" src="https://github.com/user-attachments/assets/53f156dc-819e-430d-8c5d-ff79d2c02a3b" />


7/6/26

Starting with the schematic.. yay:
Time: 3-4 hours (because I kept restarting) 

This was definitely so confusing at first because I tried watching so many YouTube videos, and it was quite useful, but it didn't help that much. Thankfully, there was an example on the GitHub example repo, so I started from what that example had and just tried to understand what was going on.  After a while, I started to understand where each part went and changed it up a little when I removed the 6th switch and added my candlelight. I had to look up a lot, but I saw that many recommended using a transistor, so I could switch off the light whenever I wanted. I added a resistor because I was a little worried that the ESP32 would blow up, which is connected to the transistor or the base. Then I added a JST connector for the candle light to plug into, where pin 1 sends power to the light while pin 2 is the return path. Understanding and learning all of this took so long, but I'm pretty satisfied with what I learned. In addition, I also learned how to use net labels, and it was helpful for making my schematic neater and cleaner. 

My schematic: 
<img width="1230" height="551" alt="jellycat cake alarm clock schematic " src="https://github.com/user-attachments/assets/6419da69-4c27-4398-bfc1-d413486a1e62" />

Then I added in my footprints. I mainly used the ones from the GitHub example repo and some in my own footprint library that I thought matched the items I'm planning to buy on Amazon. 

My footprints: 
<img width="1228" height="600" alt="jellycat cake alarm footprints" src="https://github.com/user-attachments/assets/395a07e8-11af-49e6-907c-e2ee5c45869f" />


7/7/26 

PCB designing: 
Time: 4 hours (again, such a long time because I kept restarting)

This took me a A WHILE to figure out how to trace and connect everything. ALso, during this process I learned that I mixed up my JST connector and resistor's footprints, so that was quite fun. Even though this was kinda confusing because I kept running into errors with my display's symbol's and with the 3d models, it was quite fun and rewarding after I finished this! 
<img width="1286" height="634" alt="pcb 3d" src="https://github.com/user-attachments/assets/5f21ab5b-7ccb-4e2f-8e24-78f43355f698" />
<img width="936" height="776" alt="pcb" src="https://github.com/user-attachments/assets/371852d8-374d-4dc5-91bd-bd23f99f09c2" />

7/9/26 

Adding the pcb + CAD:
Time: 2 hours

Now this was so fun to do because I actually got see my alarm come all together. Though at some monments, I wished I could change my pcb design as when I was creating the holes for my keys, buzzer and display, it looked a little weird.. but I managed to fix it to how I like it :) At that time, I also made my candle that I'm hoping to paint once I get it so I can make it really look like the real Jellycat cake. But overall, this part was quite fun and quick to finish!

here I added some mounts - not in the pic but the mounting holes are there :)
<img width="1393" height="906" alt="Screenshot 2026-07-09 181004" src="https://github.com/user-attachments/assets/781dd4f2-c418-49af-8927-7021b948ed57" />

<img width="782" height="696" alt="Screenshot 2026-07-09 180816" src="https://github.com/user-attachments/assets/bfbddc5e-e648-4756-bbf8-f3f14d49358e" />

Firmwire:

Time: 2 hours
 I only had like around 2 hours to write my code and honestly I'm not sure that I did it all right to be honest. This is my first time using Arduino IDE, which I believe is C++ (also my first time), and it was quite similar to java but I was still so confused. Especially without being able to test my code, I struggled HARD but I think I wrote somewhat of something that could work? I tried adding in a timer function where I set timers using three of my buttons that I added and also made it to display a time for right now. That is just the main features I wanted to add in my clock. 


 Resubmission:
Time: 2 hours

I made a bunch of revisions on my cad as I was asked on how my mounting worked and realized that I wouldn't even be able to put my pcb in the first place. I'm so glad that I was able to fix that before it was actually 3d printed. I also fixed a bit of my code as it was in patchy shape though I think I got most of the buttons working! I also finally added the right kicad files this time. 

<img width="853" height="833" alt="Screenshot 2026-07-15 193446" src="https://github.com/user-attachments/assets/d4f5343b-1b2c-4f98-9d51-d73f845f9af6" />
this is my mounting

 

 END OF JOURNAL 



