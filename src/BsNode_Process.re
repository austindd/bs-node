type t = {
  .
  "argv": array(string),
  "arch": string,
  [@bs.meth] "abort": unit => unit,
  [@bs.meth] "chdir": string => unit,
  /*** @raise */
  [@bs.meth] "cwd": unit => string,
  [@bs.meth] "disconnect": unit => unit,
};

[@bs.module] external process: t = "process";

[@bs.val] [@bs.module "process"] external argv: array(string) = "argv";
