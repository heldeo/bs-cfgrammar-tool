open Jest
open Expect
type cfgrammar;
[@bs.module] external cfgrammar_js: cfgrammar = "./../node_modules/cfgrammar-tool"; 

//Js.log(Cfgrammar.equals(Cfgrammar.Types.sym("NT","A"),[%raw {|new cfgrammar_js.types.Sym("NT","A")|}])) 
//let obj = Cfgrammar.Types.sym("NT","A");

//s.log([%raw {| typeof obj |}]); 

let () = 
describe ("Functionality of types submodule",()=>{
    test("Returns Symbol Object", ()=>{
        expect(Cfgrammar.compare_sym(Cfgrammar.Types.sym("NT","A"),[%raw {|new cfgrammar_js.types.Sym("NT","A")|}] )   ) |> toBe(true); 
        });
    test("Return Non-terminal (NT) with string passed into constructor", ()=>{
        expect(Cfgrammar.compare_sym(Cfgrammar.Types.nt("A"),[%raw {| cfgrammar_js.types.NT("A") |}] )) |> toBe(true);
        });
    test("Return Terminal (T)  with string passed into constructor", ()=>{
        expect(Cfgrammar.compare_sym(Cfgrammar.Types.t("A"),[%raw {| cfgrammar_js.types.T("A") |}] )) |> toBe(true);
        });

     test("Rule creation with input: (E,  [T(a),NT(B)] )", ()=>{
        let prod_rules: array(Cfgrammar.sym)  = [|Cfgrammar.Types.t("a"),Cfgrammar.Types.nt("B")|]; 


        expect(Cfgrammar.compare_rule(Cfgrammar.Types.rule("E",prod_rules),[%raw {| cfgrammar_js.types.Rule("E",prod_rules) |}] )) |> toBe(true);

        });



} );
//Cfgrammar.equals(Cfgrammar.Types.sym("NT","A"),[%raw {|new cfgrammar_js.types.Sym("NT","A")|}] ) 
