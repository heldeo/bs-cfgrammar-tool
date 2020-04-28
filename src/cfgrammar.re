type sym = {

    [@bs.as "type"] _type:string,
    data:string,
};
type rule = {

    name: string,
    production: array(sym),
    equals: (rule,rule) => bool
};
[@bs.module "cfgrammar-tool/types"][@bs.new]
external rule: (string,array(sym)) => rule = "Rule";
let rule = (name,production) => rule(name,production);

[@bs.send] 
external equals: (rule,rule) => bool = "equals";
let equals = (obj1,obj2) => equals(obj1,obj2);

[@bs.module "cfgrammar-tool/types"][@bs.new]
external sym : (string,string) => sym = "Sym";
let sym = (t,d) => sym(t,d);


[@bs.send]
external equals: (sym,sym) => bool = "equals";
let equals = (obj1,obj2) => equals(obj1,obj2);

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
