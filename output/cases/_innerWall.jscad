function board_extrude_5_6_outline_fn(){
    return new CSG.Path2D([[27.475,-207.525],[27.475,-84.75]]).appendArc([32.475,-79.75],{"radius":5,"clockwise":true,"large":false}).appendPoint([107.675,-79.75]).appendArc([112.675,-84.75],{"radius":5,"clockwise":true,"large":false}).appendPoint([112.675,-207.525]).appendArc([107.675,-212.525],{"radius":5,"clockwise":true,"large":false}).appendPoint([32.475,-212.525]).appendArc([27.475,-207.525],{"radius":5,"clockwise":true,"large":false}).close().innerToCAG()
.extrude({ offset: [0, 0, 5.6] });
}




                function _innerWall_case_fn() {
                    

                // creating part 0 of case _innerWall
                let _innerWall__part_0 = board_extrude_5_6_outline_fn();

                // make sure that rotations are relative
                let _innerWall__part_0_bounds = _innerWall__part_0.getBounds();
                let _innerWall__part_0_x = _innerWall__part_0_bounds[0].x + (_innerWall__part_0_bounds[1].x - _innerWall__part_0_bounds[0].x) / 2
                let _innerWall__part_0_y = _innerWall__part_0_bounds[0].y + (_innerWall__part_0_bounds[1].y - _innerWall__part_0_bounds[0].y) / 2
                _innerWall__part_0 = translate([-_innerWall__part_0_x, -_innerWall__part_0_y, 0], _innerWall__part_0);
                _innerWall__part_0 = rotate([0,0,0], _innerWall__part_0);
                _innerWall__part_0 = translate([_innerWall__part_0_x, _innerWall__part_0_y, 0], _innerWall__part_0);

                _innerWall__part_0 = translate([0,0,0], _innerWall__part_0);
                let result = _innerWall__part_0;
                
            
                    return result;
                }
            
            
        
            function main() {
                return _innerWall_case_fn();
            }

        