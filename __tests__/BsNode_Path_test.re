open Jest;

[@bs.module "path"] [@bs.splice] external join: array(string) => string = "join";

describe("join", _ =>
  Expect.(
    test("concat paths with sep", _ =>
      expect @@ join([|"a", "b"|]) |> toEqual("a/b")
    )
  )
);
