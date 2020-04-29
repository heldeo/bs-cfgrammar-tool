
let prod_rules: array(Cfgrammar.rule)  = Array.make(1,(Cfgrammar.rule("A", [|Cfgrammar.Types.t("a"),Cfgrammar.Types.nt("B")|]))); 
        let start = "S"; 
let gram = Cfgrammar.Types.grammar(prod_rules,start);        
Js.log(gram);
