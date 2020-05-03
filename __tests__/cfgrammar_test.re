open Jest
open Expect
type cfgrammar;
[@bs.module] external cfgrammar_js: cfgrammar = "./../node_modules/cfgrammar-tool"; 


describe ("Types submodule, Symbol, Rule and equality functionality",()=>{
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
    test("Tests reduction (string in grammar)", () =>{
    let rhs: array(Cfgrammar.sym)  = [|Cfgrammar.Types.t("a"),Cfgrammar.Types.nt("B")|]; 
    let rules = [|
    Cfgrammar.Types.rule("S",[|Cfgrammar.Types.t("a"),Cfgrammar.Types.nt("B")|]),
    Cfgrammar.Types.rule("S",[|Cfgrammar.Types.t("a")|]),
    Cfgrammar.Types.rule("B",[| |]) |];
    let grammar = Cfgrammar.grammar(rules,"S");
    let did_parse = Cfgrammar.Parse.parse(grammar,"a") 
        |> Cfgrammar.Parse.length;
    expect(did_parse > 0) |> toBe(true);
    });

}); 


