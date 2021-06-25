## Files for lasercutting

## How to create your own cloud design
I suggest to use [Inkscape](https://inkscape.org/) to create your own cloud design. Follow these steps:

(Use an area of about 140 x 80 mm for your drawing)

1. Draw circles or ellipses. The outer shape will form the outline of your cloud
<p align="center">
<img src="https://raw.githubusercontent.com/oberlab/jeanCloud/main/img/draw_cloud1.png" width="400"/>
<img src="https://raw.githubusercontent.com/oberlab/jeanCloud/main/img/draw_cloud2.png" width="400"/>
</p>

2. Select all circles and unionize them to one shape (Path > Union or press ctrl and +)

<p align="center">
<img src="https://raw.githubusercontent.com/oberlab/jeanCloud/main/img/draw_cloud3.png" width="400"/>
<img src="https://raw.githubusercontent.com/oberlab/jeanCloud/main/img/draw_cloud4.png" width="400"/>
</p>

3. Duplicate the shape (ctrl + D or right click on the shape) two times. Put one to the side for later. Create an dynamic offset with the other duplicate (Path > Dynamic offset or press ctrl + J). Pull the dynamic offset in any direction.

<p align="center">
<img src="https://raw.githubusercontent.com/oberlab/jeanCloud/main/img/draw_cloud5.png" width="400"/>
<img src="https://raw.githubusercontent.com/oberlab/jeanCloud/main/img/draw_cloud6.png" width="400"/>
</p>

4. First duplicate the offset shape (ctrl + D or right click on the shape) and put it to the side  Now subtract (Path > Difference or ctrl + -) the new smaller shape from the previous one. Again create a duplicate (ctrl + D or right click on the shape) and put it to the side for later.

<p align="center">
<img src="https://raw.githubusercontent.com/oberlab/jeanCloud/main/img/draw_cloud7.png" width="400"/>
<img src="https://raw.githubusercontent.com/oberlab/jeanCloud/main/img/draw_cloud8.png" width="300"/>
</p>

5. Create a rectangle with 70 mm width and 25 mm height and place it below the cloud. Unionize both shapes (Path > Union or press ctrl and +). This is the part you will insert into the box later.

<p align="center">
<img src="https://raw.githubusercontent.com/oberlab/jeanCloud/main/img/draw_cloud9.png" width="400"/>
<img src="https://raw.githubusercontent.com/oberlab/jeanCloud/main/img/draw_cloud10.png" width="400"/>
</p>

6. Create a a duplicate of the offset shape (from step 4) and put it into the cloud shape with the box. Subtract it from the shape (Path > Difference or ctrl + -) to get a nice inner shape again (there are better ways to do this but this one seemed easier for me).

<p align="center">
<img src="https://raw.githubusercontent.com/oberlab/jeanCloud/main/img/draw_cloud11.png" width="400"/>
<img src="https://raw.githubusercontent.com/oberlab/jeanCloud/main/img/draw_cloud12.png" width="400"/>
</p>

7. Now we need to create a channel for the LED cables. Create a small rectangle with 15 mm width (height does not matter) and place it in the middle of the bottom part and subtract it from the shape (Path > Difference or ctrl + -).

<p align="center">
<img src="https://raw.githubusercontent.com/oberlab/jeanCloud/main/img/draw_cloud13.png" width="400"/>
<img src="https://raw.githubusercontent.com/oberlab/jeanCloud/main/img/draw_cloud14.png" width="400"/>
</p>

8. Quick check. You should now have 4 shapes on your inkscape document: 1. Outline with connector and cable channel (from step 7), 2. Outline (from step 4), 3. Offset cloud shape (from step 4) and 4. Cloud shape (from step 2).

<p align="center">
<img src="https://raw.githubusercontent.com/oberlab/jeanCloud/main/img/draw_cloud15.png" width="400"/>
</p>

9. Now let's create the parts which hold the veneer/white sheet for the light. Duplicate the outline shape created in step 4 (number in the previous picture) and drag it to the side. Lay the cloud shape over the duplicated outline.

<p align="center">
<img src="https://raw.githubusercontent.com/oberlab/jeanCloud/main/img/draw_cloud16.png" width="400"/>
<img src="https://raw.githubusercontent.com/oberlab/jeanCloud/main/img/draw_cloud17.png" width="400"/>
</p>

10. Select the cloud shape and do a dynamic offset again (Path > Dynamic offset or press ctrl + J) and pull it in the middle of the Cloud Outline. You might have to zoom in to get it right.

<p align="center">
<img src="https://raw.githubusercontent.com/oberlab/jeanCloud/main/img/draw_cloud18.png" width="400"/>
<img src="https://raw.githubusercontent.com/oberlab/jeanCloud/main/img/draw_cloud19.png" width="400"/>
</p>

11. Create a duplicate of the new shape and put it to the side. Now select both overlaying shapes and create an intersection (Path > Intersection or ctrl + *)

<p align="center">
<img src="https://raw.githubusercontent.com/oberlab/jeanCloud/main/img/draw_cloud20.png" width="400"/>
<img src="https://raw.githubusercontent.com/oberlab/jeanCloud/main/img/draw_cloud21.png" width="400"/>
</p>

12. For the last part create a duplicate of the cloud outline again and a duplicate from the smaller cloud shape we created in step 10/11. Drag them both to the side and lay them over each other. It is important that the bigger shape is below the smaller shape. You can change the order in the toolbar. They should be also perfectly centred to each other. You can do this by using the Align and Distribute tool (Object > Align and Distribute)  Finally subtract the shapes (Path > Difference or ctrl + -).

<p align="center">
<img src="https://raw.githubusercontent.com/oberlab/jeanCloud/main/img/draw_cloud22.png" width="400"/>
<img src="https://raw.githubusercontent.com/oberlab/jeanCloud/main/img/draw_cloud23.png" width="400"/>
<img src="https://raw.githubusercontent.com/oberlab/jeanCloud/main/img/draw_cloud24.png" width="400"/>
</p>

13. Final check! Now you should have 5 shapes! 1. The outer outline (from step 12), the cloud outline, 3. the inner outline (from step 11), 4. outline with connector and cable channel (from step 7) and 5. smaller cloud shape from step 11.

<p align="center">
<img src="https://raw.githubusercontent.com/oberlab/jeanCloud/main/img/draw_cloud25.png" width="500"/>
</p>


### Box generators
- [MakerCase](https://de.makercase.com/)
- [boxes.py](https://www.festi.info/boxes.py/)
