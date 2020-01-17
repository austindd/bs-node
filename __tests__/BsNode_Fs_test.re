open Jest;

describe("content", _ =>
  ExpectJs.(
    test("non-zero length", _ =>
      expect(
        switch ([%node __filename]) {
        | None => 0
        | Some(filename) =>
          Node.Fs.readFileSync(filename, `utf8) |> String.length
        },
      )
      |> toBeTruthy
    )
  )
);
