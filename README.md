# Context-Free Grammars for ReasonML/Bucklescript
![Badge_Build](https://github.com/heldeo/bs-cfgrammar-tool/workflows/Build/badge.svg)
[<img src="https://upload.wikimedia.org/wikipedia/commons/d/db/Npm-logo.svg" width="10%"> ](https://www.npmjs.com/package/bs-cfgrammar-tool)

This repository contains in-progress Reason/Bucklescript bindings for [Cfgrammar-tool](https://github.com/bakkot/cfgrammar-tool).

## Example

This is an example from [Cfgrammar-tool](https://github.com/bakkot/cfgrammar-tool) written in Reason using bs-cfgrammar-tool:

```vim
open Cfgrammar;

let t =  Types.t;
let nt = Types.nt;
let rule = Types.rule;

let exprGrammar = grammar([|
    rule("E", [| nt("E"), t("+"), nt("T")|]),    
    rule("E", [| nt("T")|]),
    rule("T", [| nt("T"), t("*"), nt("F") |]),
    rule("T", [| nt("F") |]),
    rule("F", [| t("("), nt("E"), t(")") |]),
    rule("F", [| t("n") |])
|],"E" );

Parse.parse(exprGrammar, "n*(n+n)")
        |> Parse.length > 0; //true
 Parse.parse(exprGrammar, "n(n+n)")
        |> Parse.length > 0; //false

let generator = generator(exprGrammar,~determinism=false);
let produced: string = generate(generator,21); // something like 'n*((n+(n)*n+n+n*n))*n'

```
 

## Installation

1.  Install the bindings using `npm install --save bs-cfgrammar-tool`
2.  Add the bindings to `bsconfig.json`:
```
{
  "bs-dependencies": [
      "bs-cfgrammar-tool"
  ]
}
```

## Build

```
npm run build
```

## Build and Watch

```
npm run watch
```

## Current State & Todo

Unopinionated porting, functionality for both instantiating grammars, generating strings from the grammars, and verifying if a string reduces to the grammar. Code is still not completey cleaned or more flavored to Ocaml yet, still in progress and would gladly take contributions.
