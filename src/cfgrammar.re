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

[@bs.module "cfgrammar-tool/types"][@bs.new]
external rule: (string,array(sym)) => rule = "Rule";
let rule = (name,production) => rule(name,production);

//let compare_rule= (obj1,obj2) => equals(obj1,obj2);

[@bs.module "cfgrammar-tool/types"][@bs.new]
external sym : (string,string) => sym = "Sym";
let sym = (t,d) => sym(t,d);
type sub_types = [`Rule(rule) | `Sym(sym) ];
[@bs.send] external equals : (rule,rule) => bool = "equals";
let compare_rule = (obj1,obj2) => equals(obj1,obj2);
[@bs.send] external equals: (sym,sym) => bool = "equals";
let compare_sym = (obj1,obj2) => equals(obj1,obj2);

let equals = (obj1: sub_types,obj2:sub_types) => switch(obj1,obj2){
    | (`Rule(obj1),`Rule(obj2)) => compare_rule(obj1,obj2);
    | (`Sym(obj1),`Sym(obj2)) => compare_sym(obj1,obj2);
};
//[@bs.send]
//external equals: (sym,sym) => bool = "equals";
//let compare_sym= (obj1,obj2) => equals(obj1,obj2);

module type Types_sig = {
    let sym: (string,string) => sym;
    let nt: (string) => sym; 
    let t: (string) => sym;
    let rule : (string,array(sym)) => rule;
};
module Types:Types_sig =
{
    let sym = (t,d) => sym(t,d);
    let nt = (d) => sym("NT",d);
    let t = (d) => sym("T",d); 
    let rule  = (n,p) => rule(n,p); 
    // Rule:Rule,
    //Grammar:Grammar

};
module type Cfgrammar_sig = 
{
    type types ;
    let types: unit=>  types;
};

module Cfgrammar: Cfgrammar_sig = 
{
    type types = Types;  
    let types = () => Types
};

//Js.log(cfgrammar.types.Sym("w","w"));

/*
   bs.module "cfgrammar-tool"] [@bs.val]
   external types : () => `types = "types"; 

   let types = () => types 
 */

Js.log( equals(`Sym(Types.nt("A")),`Sym(Types.nt("A"))))
