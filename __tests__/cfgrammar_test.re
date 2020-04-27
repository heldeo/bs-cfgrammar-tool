open Jest;
open Cfgrammar;

let () = 
    describe("cfgrammar",
            ExpectJs.(
                ()=>{
                        test("#types",()=> 
                             expect(Cfgrammar.types)|> toBe(0)
                             );

                
                }
            ),
        );
