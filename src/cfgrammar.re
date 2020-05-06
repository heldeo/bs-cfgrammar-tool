type sym = {

    [@bs.as "type"] _type:string,
    data:string,
    equals: (sym,sym) => bool,
};
type rule = {

    name: string,
    production: array(sym),
    equals: (rule,rule) => bool,
};
type grammar = {
    rules: array(rule),
    start: string
};
[@bs.new]
external rule: (string,array(sym)) => rule = "Rule";
let rule = (name,production) => rule(name,production);

[@bs.module "cfgrammar-tool/types"][@bs.new]
external sym : (string,string) => sym = "Sym";
let sym = (t,d) => sym(t,d);

[@bs.module "cfgrammar-tool/types"][@bs.new]
external grammar: (array(rule),string) => grammar = "Grammar";
let grammar = (rules,start) => grammar(rules,start);
/* polymorphic variant constructors to have equals constructor be polyomorphic */
type sub_types = [`Rule(rule) | `Sym(sym) ];

[@bs.send] external equals : (rule,rule) => bool = "equals";
let compare_rule = (obj1,obj2) => equals(obj1,obj2);
[@bs.send] external equals: (sym,sym) => bool = "equals";
let compare_sym = (obj1,obj2) => equals(obj1,obj2);

//Pattern matches on sub_types to do correct equality comparison
let equals = (obj1: sub_types,obj2:sub_types) => switch(obj1,obj2){
    | (`Rule(obj1),`Rule(obj2)) => compare_rule(obj1,obj2);
    | (`Sym(obj1),`Sym(obj2)) => compare_sym(obj1,obj2);
    | _=>           exception TypeMismatched(string);
                    raise(TypeMismatched("Rule comparison with Symbol"));
    };

module type Types_sig = {
    let sym: (string,string) => sym;
    let nt: (string) => sym; 
    let t: (string) => sym;
    let rule : (string,array(sym)) => rule;
    let grammar :(array(rule),string) => grammar;
};
module Types:Types_sig =
{
    let sym = (t,d) => sym(t,d);
    let nt = (d) => sym("NT",d);
    let t = (d) => sym("T",d); 
    let rule  = (n,p) => rule(n,p); 
    let grammar = (rules,start) => grammar(rules,start);

};
type parse;
[@bs.module "cfgrammar-tool/parser"][@bs.val]
external parse: (grammar,string ) => parse= "parse";

let __len_identity: (parse) => int = [%bs.raw {|
        function(parse){
        return parse.length;
        }    
|}];


module type Parse_sig = {
    let parse: (grammar,string ) => parse;
    let length: (parse) => int; 
    };
module Parse:Parse_sig = {
    let parse =  (grammar,str) => parse(grammar,str); 
    let length = (parse) => __len_identity(parse);
}

type generator;
[@bs.module "cfgrammar-tool"]
external generator: (grammar,~determinism:bool=?) => generator =  "generator";

let __gen_identity: (generator,int) => string = [%bs.raw {| 

    function(gen,cardinality) {

    return gen(cardinality);
    }

|}]; 

let generate = (gen,card) => __gen_identity(gen,card); 
