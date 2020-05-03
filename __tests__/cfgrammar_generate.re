open Jest
open Expect

type cfgrammar;
[@bs.module] external cfgrammar_js: cfgrammar = "./../node_modules/cfgrammar-tool"; 
/* Grammar tested:
   S => aB
   S => a
   B => S
   B => ! epsilon
 */
let rules = [|
Cfgrammar.Types.rule("S",[|Cfgrammar.Types.t("a"),Cfgrammar.Types.nt("B")|]),
    Cfgrammar.Types.rule("S",[|Cfgrammar.Types.t("a")|]),
    Cfgrammar.Types.rule("B",[|Cfgrammar.Types.nt("S") |]),
    Cfgrammar.Types.rule("B",[| |])
    |];
    let grammar = Cfgrammar.grammar(rules,"S");

    let generator:Cfgrammar.generator = Cfgrammar.generator(grammar,~determinism=true);

    describe ("Testing generator",()=>{
        test("Create generator test (generator(g,~d) tested))", ()=>{
            expect( [%raw {| generator.toString() |}] )  |> toBe( [%raw {| cfgrammar_js.generator(grammar,true).toString() |}] );
            });


        test("Generator produces test string \"a\" (generate(g,c) tested)", ()=>{
            expect( Cfgrammar.generate( generator,1) )  |> toBe( [%raw {| cfgrammar_js.generator(grammar,true)(1) |}] ); 

            });
        test("Generator produces test string \"aa\" (generate(g,c) tested)", ()=>{
            expect( Cfgrammar.generate( generator,2) )  |> toBe( [%raw {| cfgrammar_js.generator(grammar,true)(2) |}] ); 

            });
        test("Generator produces test string \"aaa\" (generate(g,c) tested)", ()=>{
            expect( Cfgrammar.generate( generator,3) )  |> toBe( [%raw {| cfgrammar_js.generator(grammar,true)(3) |}] ); 

            });




    }); 


