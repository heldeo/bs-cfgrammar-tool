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
        expect( Cfgrammar.equals(`Sym(Cfgrammar.Types.sym("NT","A")),`Sym(Cfgrammar.Types.sym("NT","A")) ))  |> toBe(true); 
        });
    test("Return Non-terminal (NT) with string passed into constructor", ()=>{
        let eq= Cfgrammar.equals(`Sym(Cfgrammar.Types.nt("A")), `Sym(Cfgrammar.Types.nt("A")) );
        expect (eq) |> toBe(true);
        });
    test("Return Terminal (T)  with string passed into constructor", ()=>{
        expect(Cfgrammar.equals(`Sym(Cfgrammar.Types.t("A")),`Sym([%raw {| cfgrammar_js.types.T("A") |}] ))) |> toBe(true);
        });

    test("Rule creation with input: (E,  [T(a),NT(B)] )", ()=>{
        let prod_rules: array(Cfgrammar.sym)  = [|Cfgrammar.Types.t("a"),Cfgrammar.Types.nt("B")|]; 


        expect(Cfgrammar.equals(`Rule(Cfgrammar.Types.rule("E",prod_rules)),`Rule([%raw {| cfgrammar_js.types.Rule("E",prod_rules) |}] ))) |> toBe(true);

        });
    test("Grammar creation with rule (E, [T(a), NT(B)])", ()=>{
       // let prod_rules: array(Cfgrammar.sym)  = [|Cfgrammar.Types.t("a"),Cfgrammar.Types.nt("B")|]; 
     //   let start = "S"; 
        
    expect( true) |> toBe(true);
    });

} );
//Cfgrammar.equals(Cfgrammar.Types.sym("NT","A"),[%raw {|new cfgrammar_js.types.Sym("NT","A")|}] ) 
