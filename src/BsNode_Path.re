
[@bs.module "path"] external basename: string => string = "basename";
[@bs.module "path"] external basenameExt: (~path: string, ~ext: string) => string = "basename";

[@bs.module "path"] external delimiter: string = "delimiter";

[@bs.module "path"] external dirname : string => string = "dirname";

[@bs.deriving abstract]
type pathObject = {
  dir: string,
  root: string,
  base: string,
  name: string,
  ext: string,
};

[@bs.module "path"] external format : pathObject => string = "format";

[@bs.module "path"] external isAbsolute : string => bool = "isAbsolute";

/* TODO: improve after we support [@bs.rest] calling convention  */
[@bs.module "path"] external join2 : string => string => string = "join";

[@bs.module "path"] [@bs.splice] external join: (array(string)) => string = "join"
   
[@bs.module "path"] external normalize : string => string = "normalize";

/* TODO: check if there is an exception raised */
[@bs.module "path"] external parse : string => pathObject = "parse";

/* TODO: provide bindings to [path.posix]*/

[@bs.module "path"] external relative : (~from:string, ~to_:string) => unit => string = "relative";

[@bs.module "path"] [@bs.splice] external resolve : array(string) => string = "resolve";

[@bs.module "path"] external sep : string = "sep";

/* TODO: provides [path.win32] */
