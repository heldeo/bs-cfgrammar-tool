
type sym = {

    [@bs.as "type"] _type:string,
    data:string,
};

[@bs.module "cfgrammar-tool/types"][@bs.new]
external sym : (string,string) => sym = "Sym";
let sym= (t,d) => sym(t,d);

module type Types_sig = {
    let sym: (string,string) => sym;
};
module Types:Types_sig =
{
    let sym = (t,d) => sym(t,d);
   // NT: NT,
    //T:,
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
Js.log(Types.sym("w","w"));

//Js.log(cfgrammar.types.Sym("w","w"));

/*
   bs.module "cfgrammar-tool"] [@bs.val]
   external types : () => `types = "types"; 

   let types = () => types 
 */
