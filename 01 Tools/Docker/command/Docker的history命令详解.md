# Docker的history命令详解

```bash
docker history -h
Flag shorthand -h has been deprecated, use --help
Usage:  docker history [OPTIONS] IMAGE

Show the history of an image

Aliases:
  docker image history, docker history

Options:
      --format string     Format output using a custom template:
                          'table':            Print output in table
                          format with column headers (default)
                          'table TEMPLATE':   Print output in table
                          format using the given Go template
                          'json':             Print in JSON format
                          'TEMPLATE':         Print output using the
                          given Go template.
                          Refer to https://docs.docker.com/go/formatting/
                          for more information about formatting output
                          with templates
  -H, --human             Print sizes and dates in human readable format
                          (default true)
      --no-trunc          Don't truncate output
      --platform string   Show history for the given platform. Formatted
                          as "os[/arch[/variant]]" (e.g., "linux/amd64")
  -q, --quiet             Only show image IDs
```
