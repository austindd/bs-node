[@bs.module "fs"] external readdirSync: string => array(string) = "readdirSync";
[@bs.module "fs"] external renameSync: string => string = "renameSync";

type fd = pri int;

/**
   The relative path to a filename can be used. Remember, however, that this path
   will be relative to [process.cwd()].
*/

type path = string;

module Watch = {
  type t;
  type config;
  [@bs.obj] external config: (
      ~persistent: bool=?,
      ~recursive: bool=?,
      ~encoding: Js_string.t=?,
      unit
    ) => config = "";

  /** there is no need to accept listener, since we return a [watcher]
      back it can register event listener there .
      Currently we introduce a type [stringBuffer], for the
      [filename], it will be [Buffer] when the encoding is `utf8.
      This is dependent type which can be tracked by GADT in some way,
      but to make things simple, let's just introduce an or type
  */
  [@bs.module "fs"] external watch: (string, ~config: config=?, unit) => t = "watch";

  /** there is no need to accept listener, since we return a [watcher]
      back it can register event listener there .
      Currently we introduce a type [stringBuffer], for the
      [filename], it will be [Buffer] when the encoding is `utf8.
      This is dependent type which can be tracked by GADT in some way,
      but to make things simple, let's just introduce an or type
  */
  [@bs.send] external on: (
    t,
    [@bs.string] [
      | `change((. string /*eventType*/, BsNode_StringBuffer.t /* filename */) => unit)
      | `error((. unit) => unit)
    ]) => t
    = "on";

  [@bs.send] external close: (t, unit) => unit = "close";
};

[@bs.module "fs"] external ftruncateSync: (fd, int) => unit = "ftruncateSync";

[@bs.module "fs"] external truncateSync: (string, int) => unit = "truncateSync";

[@bs.module "fs"] external chownSync: (string, ~uid: int, ~gid: int) => unit = "chownSync";

[@bs.module "fs"] external fchownSync: (fd, ~uid: int, ~gid: int) => unit = "fchownSync";

[@bs.module "fs"] external fchmodSync: (fd, ~uid: int) => unit = "fchmodSync";

[@bs.module "fs"] external readlinkSync: string => string = "readlinkSync";

[@bs.module "fs"] external unlinkSync: string => unit = "unlinkSync";

[@bs.module "fs"] external rmdirSync: string => unit = "rmdirSync";

/* TODO: [flags] support */
[@bs.module "fs"] external openSync: (
  path,
  [@bs.string] [
    | [@bs.as "r"] `Read
    | [@bs.as "r+"] `ReadWrite
    | [@bs.as "rs+"] `ReadWriteSync
    | [@bs.as "w"] `Write
    | [@bs.as "wx"] `WriteFailIfExists
    | [@bs.as "w+"] `WriteRead
    | [@bs.as "wx+"] `WriteReadFailIfExists
    | [@bs.as "a"] `Append
    | [@bs.as "ax"] `AppendFailIfExists
    | [@bs.as "a+"] `AppendRead
    | [@bs.as "ax+"] `AppendReadFailIfExists
  ]) => unit
  = "openSync";

[@bs.val] [@bs.module "fs"]
external readFileSync: (
  string,
  [@bs.string] [
    | `hex
    | `utf8
    | `ascii
    | `latin1
    | `base64
    | `ucs2
    | `base64
    | `binary
    | `utf16le
  ]) => string
  = "readFileSync";

[@bs.val] [@bs.module "fs"] external readFileAsUtf8Sync: (string, [@bs.as "utf8"] _) => string = "readFileSync";

[@bs.val] [@bs.module "fs"] external existsSync: string => bool = "existsSync";

[@bs.val] [@bs.module "fs"] external writeFileSync: (~filename: string, ~text: string) => unit = "writeFileSync";

[@bs.val] [@bs.module "fs"] external mkdirSync: string => unit = "mkdirSync";
