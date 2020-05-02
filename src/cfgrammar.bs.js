// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var Caml_exceptions = require("bs-platform/lib/js/caml_exceptions.js");
var Types = require("cfgrammar-tool/types");
var Parser = require("cfgrammar-tool/parser");

function rule(name, production) {
  return new Types.Rule(name, production);
}

function sym(t, d) {
  return new Types.Sym(t, d);
}

function grammar(rules, start) {
  return new Types.Grammar(rules, start);
}

function compare_rule(obj1, obj2) {
  return obj1.equals(obj2);
}

function compare_sym(obj1, obj2) {
  return obj1.equals(obj2);
}

function equals(obj1, obj2) {
  if (obj1[0] >= 915186972) {
    if (typeof obj2 !== "number" && obj2[0] === 915186972) {
      return obj1[1].equals(obj2[1]);
    }
    
  } else if (typeof obj2 !== "number" && obj2[0] === 4154599) {
    return obj1[1].equals(obj2[1]);
  }
  var TypeMismatched = Caml_exceptions.create("TypeMismatched");
  throw [
        TypeMismatched,
        "Rule comparison with Symbol"
      ];
}

function sym$1(t, d) {
  return new Types.Sym(t, d);
}

function nt(d) {
  return new Types.Sym("NT", d);
}

function t(d) {
  return new Types.Sym("T", d);
}

function rule$1(n, p) {
  return new Types.Rule(n, p);
}

function grammar$1(rules, start) {
  return new Types.Grammar(rules, start);
}

var Types$1 = {
  sym: sym$1,
  nt: nt,
  t: t,
  rule: rule$1,
  grammar: grammar$1
};

function parse(grammar, str, produceCount) {
  return Parser.parser(grammar, str, produceCount);
}

var Parse = {
  parse: parse
};

var __gen_identity = (function(gen,cardinality) {

    return gen(cardinality);
    });

var generate = __gen_identity;

exports.rule = rule;
exports.sym = sym;
exports.grammar = grammar;
exports.compare_rule = compare_rule;
exports.compare_sym = compare_sym;
exports.equals = equals;
exports.Types = Types$1;
exports.Parse = Parse;
exports.__gen_identity = __gen_identity;
exports.generate = generate;
/* cfgrammar-tool/types Not a pure module */
