function board_extrude_1_outline_fn(){
    return new CSG.Path2D([[27.475,-207.525],[27.475,-79.75]]).appendArc([32.475,-74.75],{"radius":5,"clockwise":true,"large":false}).appendPoint([107.675,-74.75]).appendArc([112.675,-79.75],{"radius":5,"clockwise":true,"large":false}).appendPoint([112.675,-207.525]).appendArc([107.675,-212.525],{"radius":5,"clockwise":true,"large":false}).appendPoint([32.475,-212.525]).appendArc([27.475,-207.525],{"radius":5,"clockwise":true,"large":false}).close().innerToCAG()
.extrude({ offset: [0, 0, 1] });
}




                function bottom_case_fn() {
                    

                // creating part 0 of case bottom
                let bottom__part_0 = board_extrude_1_outline_fn();

                // make sure that rotations are relative
                let bottom__part_0_bounds = bottom__part_0.getBounds();
                let bottom__part_0_x = bottom__part_0_bounds[0].x + (bottom__part_0_bounds[1].x - bottom__part_0_bounds[0].x) / 2
                let bottom__part_0_y = bottom__part_0_bounds[0].y + (bottom__part_0_bounds[1].y - bottom__part_0_bounds[0].y) / 2
                bottom__part_0 = translate([-bottom__part_0_x, -bottom__part_0_y, 0], bottom__part_0);
                bottom__part_0 = rotate([0,0,0], bottom__part_0);
                bottom__part_0 = translate([bottom__part_0_x, bottom__part_0_y, 0], bottom__part_0);

                bottom__part_0 = translate([0,0,0], bottom__part_0);
                let result = bottom__part_0;
                
            
                    return result;
                }
            
            
        
            function main() {
                return bottom_case_fn();
            }

        