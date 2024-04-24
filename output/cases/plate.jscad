function plate_extrude_1_outline_fn(){
    return new CSG.Path2D([[108.15,-205.405],[108.15,-198.405]]).appendPoint([92.15,-198.405]).appendPoint([92.15,-205.405]).appendPoint([108.15,-205.405]).close().innerToCAG()
.union(
    new CSG.Path2D([[34.595,-208],[41.595,-208]]).appendPoint([41.595,-192]).appendPoint([34.595,-192]).appendPoint([34.595,-208]).close().innerToCAG()
).union(
    new CSG.Path2D([[31.8,-187.8667185],[31.8,-112.8]]).appendArc([33,-111.6],{"radius":1.2,"clockwise":true,"large":false}).appendPoint([107.15,-111.6]).appendArc([108.35,-112.8],{"radius":1.2,"clockwise":true,"large":false}).appendPoint([108.35,-197.4333592]).appendArc([107.6866563,-198.5066718],{"radius":1.2,"clockwise":true,"large":false}).appendPoint([88.5533748,-208.0733126]).appendArc([88.0167185,-208.2],{"radius":1.2,"clockwise":true,"large":false}).appendPoint([42.5666408,-208.2]).appendArc([41.4933282,-207.5366563],{"radius":1.2,"clockwise":true,"large":false}).appendPoint([31.9266874,-188.4033748]).appendArc([31.8,-187.8667185],{"radius":1.2,"clockwise":true,"large":false}).close().innerToCAG()
.subtract(
    new CSG.Path2D([[108.15,-165.305],[108.15,-158.305]]).appendPoint([92.15,-158.305]).appendPoint([92.15,-165.305]).appendPoint([108.15,-165.305]).close().innerToCAG()
.union(
    new CSG.Path2D([[108.15,-141.445],[108.15,-134.445]]).appendPoint([92.15,-134.445]).appendPoint([92.15,-141.445]).appendPoint([108.15,-141.445]).close().innerToCAG()
).union(
    new CSG.Path2D([[108.15,-181.545],[108.15,-174.545]]).appendPoint([92.15,-174.545]).appendPoint([92.15,-181.545]).appendPoint([108.15,-181.545]).close().innerToCAG()
).union(
    new CSG.Path2D([[58.455,-208],[65.455,-208]]).appendPoint([65.455,-192]).appendPoint([58.455,-192]).appendPoint([58.455,-208]).close().innerToCAG()
).union(
    new CSG.Path2D([[93.15,-126.8],[107.15,-126.8]]).appendPoint([107.15,-112.8]).appendPoint([93.15,-112.8]).appendPoint([93.15,-126.8]).close().innerToCAG()
).union(
    new CSG.Path2D([[107.15,-156.875],[107.15,-142.875]]).appendPoint([93.15,-142.875]).appendPoint([93.15,-156.875]).appendPoint([107.15,-156.875]).close().innerToCAG()
).union(
    new CSG.Path2D([[107.15,-196.975],[107.15,-182.975]]).appendPoint([93.15,-182.975]).appendPoint([93.15,-196.975]).appendPoint([107.15,-196.975]).close().innerToCAG()
).union(
    new CSG.Path2D([[73.1,-126.8],[87.1,-126.8]]).appendPoint([87.1,-112.8]).appendPoint([73.1,-112.8]).appendPoint([73.1,-126.8]).close().innerToCAG()
).union(
    new CSG.Path2D([[73.1,-146.85],[87.1,-146.85]]).appendPoint([87.1,-132.85]).appendPoint([73.1,-132.85]).appendPoint([73.1,-146.85]).close().innerToCAG()
).union(
    new CSG.Path2D([[73.1,-166.9],[87.1,-166.9]]).appendPoint([87.1,-152.9]).appendPoint([73.1,-152.9]).appendPoint([73.1,-166.9]).close().innerToCAG()
).union(
    new CSG.Path2D([[73.1,-186.95],[87.1,-186.95]]).appendPoint([87.1,-172.95]).appendPoint([73.1,-172.95]).appendPoint([73.1,-186.95]).close().innerToCAG()
).union(
    new CSG.Path2D([[73.1,-207],[87.1,-207]]).appendPoint([87.1,-193]).appendPoint([73.1,-193]).appendPoint([73.1,-207]).close().innerToCAG()
).union(
    new CSG.Path2D([[53.05,-126.8],[67.05,-126.8]]).appendPoint([67.05,-112.8]).appendPoint([53.05,-112.8]).appendPoint([53.05,-126.8]).close().innerToCAG()
).union(
    new CSG.Path2D([[53.05,-146.85],[67.05,-146.85]]).appendPoint([67.05,-132.85]).appendPoint([53.05,-132.85]).appendPoint([53.05,-146.85]).close().innerToCAG()
).union(
    new CSG.Path2D([[53.05,-166.9],[67.05,-166.9]]).appendPoint([67.05,-152.9]).appendPoint([53.05,-152.9]).appendPoint([53.05,-166.9]).close().innerToCAG()
).union(
    new CSG.Path2D([[53.05,-186.95],[67.05,-186.95]]).appendPoint([67.05,-172.95]).appendPoint([53.05,-172.95]).appendPoint([53.05,-186.95]).close().innerToCAG()
).union(
    new CSG.Path2D([[33,-126.8],[47,-126.8]]).appendPoint([47,-112.8]).appendPoint([33,-112.8]).appendPoint([33,-126.8]).close().innerToCAG()
).union(
    new CSG.Path2D([[33,-146.85],[47,-146.85]]).appendPoint([47,-132.85]).appendPoint([33,-132.85]).appendPoint([33,-146.85]).close().innerToCAG()
).union(
    new CSG.Path2D([[33,-166.9],[47,-166.9]]).appendPoint([47,-152.9]).appendPoint([33,-152.9]).appendPoint([33,-166.9]).close().innerToCAG()
).union(
    new CSG.Path2D([[33,-186.95],[47,-186.95]]).appendPoint([47,-172.95]).appendPoint([33,-172.95]).appendPoint([33,-186.95]).close().innerToCAG()
).union(
    new CSG.Path2D([[43.025,-207],[57.025,-207]]).appendPoint([57.025,-193]).appendPoint([43.025,-193]).appendPoint([43.025,-207]).close().innerToCAG()
))).extrude({ offset: [0, 0, 1] });
}




                function plate_case_fn() {
                    

                // creating part 0 of case plate
                let plate__part_0 = plate_extrude_1_outline_fn();

                // make sure that rotations are relative
                let plate__part_0_bounds = plate__part_0.getBounds();
                let plate__part_0_x = plate__part_0_bounds[0].x + (plate__part_0_bounds[1].x - plate__part_0_bounds[0].x) / 2
                let plate__part_0_y = plate__part_0_bounds[0].y + (plate__part_0_bounds[1].y - plate__part_0_bounds[0].y) / 2
                plate__part_0 = translate([-plate__part_0_x, -plate__part_0_y, 0], plate__part_0);
                plate__part_0 = rotate([0,0,0], plate__part_0);
                plate__part_0 = translate([plate__part_0_x, plate__part_0_y, 0], plate__part_0);

                plate__part_0 = translate([0,0,0], plate__part_0);
                let result = plate__part_0;
                
            
                    return result;
                }
            
            
        
            function main() {
                return plate_case_fn();
            }

        