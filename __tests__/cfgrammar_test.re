open Jest
open Expect
type cfgrammar;
[@bs.module] external cfgrammar_js: cfgrammar = "./../node_modules/cfgrammar-tool"; 

Js.log(Cfgrammar.equals(Cfgrammar.Types.sym("NT","A"),[%raw {|new cfgrammar_js.types.Sym("NT","A")|}])) 
let obj = Cfgrammar.Types.sym("NT","A");

Js.log([%raw {| typeof obj |}]); 

let () = test("Returns Symbol Object", ()=>{
    expect(Cfgrammar.equals(Cfgrammar.Types.sym("NT","A"),[%raw {|new cfgrammar_js.types.Sym("NT","A")|}] )   ) |> toBe(true); 
    });
//Cfgrammar.equals(Cfgrammar.Types.sym("NT","A"),[%raw {|new cfgrammar_js.types.Sym("NT","A")|}] ) 
