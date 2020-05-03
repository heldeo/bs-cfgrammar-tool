open Jest
open Expect

let rules = [|
        Cfgrammar.Types.rule("S",[|Cfgrammar.Types.t("a"),Cfgrammar.Types.nt("B")|]),
        Cfgrammar.Types.rule("S",[|Cfgrammar.Types.t("a")|]),
        Cfgrammar.Types.rule("B",[| |]) |];
        let grammar = Cfgrammar.grammar(rules,"S");
          
describe ("Parsing/reduction tests",()=>{
        test("Tests reduction (string in grammar)", () =>{
            let did_parse = Cfgrammar.Parse.parse(grammar,"a")
                |> Cfgrammar.Parse.length;
                expect(did_parse > 0) |> toBe(true);
                });
}); 


