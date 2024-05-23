# go work 命令的用法

## go work use

```bash
go work use ./path/to/module
go work use -r ./path/to/module
```

## 查看帮助详情

1. edit        edit go.work from tools or scripts
2. init        initialize workspace file
3. sync        sync workspace build list to modules
4. use         add modules to workspace file
5. vendor      make vendored copy of dependencies

`go work help`

```shell
go work help
Work provides access to operations on workspaces.

Note that support for workspaces is built into many other commands, not
just 'go work'.

See 'go help modules' for information about Go's module system of which
workspaces are a part.

See https://go.dev/ref/mod#workspaces for an in-depth reference on
workspaces.

See https://go.dev/doc/tutorial/workspaces for an introductory
tutorial on workspaces.

A workspace is specified by a go.work file that specifies a set of
module directories with the "use" directive. These modules are used as
root modules by the go command for builds and related operations.  A
workspace that does not specify modules to be used cannot be used to do
builds from local modules.

go.work files are line-oriented. Each line holds a single directive,
made up of a keyword followed by arguments. For example:

        go 1.18

        use ../foo/bar
        use ./baz

        replace example.com/foo v1.2.3 => example.com/bar v1.4.5

The leading keyword can be factored out of adjacent lines to create a block,
like in Go imports.

        use (
          ../foo/bar
          ./baz
        )

The use directive specifies a module to be included in the workspace's
set of main modules. The argument to the use directive is the directory
containing the module's go.mod file.

The go directive specifies the version of Go the file was written at. It
is possible there may be future changes in the semantics of workspaces
that could be controlled by this version, but for now the version
specified has no effect.

The replace directive has the same syntax as the replace directive in a
go.mod file and takes precedence over replaces in go.mod files.  It is
primarily intended to override conflicting replaces in different workspace
modules.

To determine whether the go command is operating in workspace mode, use
the "go env GOWORK" command. This will specify the workspace file being
used.

Usage:

        go work <command> [arguments]

The commands are:

        edit        edit go.work from tools or scripts
        init        initialize workspace file
        sync        sync workspace build list to modules
        use         add modules to workspace file
        vendor      make vendored copy of dependencies

Use "go help work <command>" for more information about a command.
```
