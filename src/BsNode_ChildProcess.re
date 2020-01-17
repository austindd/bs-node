type t;

[@bs.module "child_process"] external execSync: string => BsNode_Options.t => string = "execSync";
