
# Resource Names
In resource-oriented APIs, resources are named entities, and resource names are their identifiers. Each resource must have its own unique resource name. The resource name is made up of the ID of the resource itself, the IDs of any parent resources, and its API service name.

Example 1: A storage service has a collection of buckets, where each bucket has a collection of objects:

| API Service Name          | Collection ID | Resource ID | Collection ID | Resource ID |
| //storage.googleapis.com  | /buckets      | /bucket-id  | /objects      | /object-id  |

Example 2: An email service has a collection of users. Each user has a settings sub-resource, and the settings sub-resource has a number of other sub-resources, including customFrom:

| API Service Name      | Collection ID | Resource ID       | Resource ID | Resource ID |
| //mail.googleapis.com | /users        | /name@example.com | /settings   | /customFrom |

## Full Resource Name
A scheme-less URI consisting of a DNS-compatible API service name and a resource path. The resource path is also known as relative resource name.

```
//library.googleapis.com/shelves/shelf1/books/book2
```

## Relative Resource Name
A URI path (path-noscheme) without the leading "/". It identifies a resource within the API service. For example:

```
shelves/shelf1/books/book2
```

## Resource Name vs URL
Convert full resource name to REST URL

```
//calendar.googleapis.com/users/john smith/events/123
//<api_service_name>/<collection_id>/<resource_id>/<collection_id>/<resource_id>


https://calendar.googleapis.com/v3/users/john%20smith/events/123
<https_scheme>//<api_service_name>/<api_version>/<collection_id>/<resource_id>/<collection_id>/<resource_id>
```

## Resource Name as String
For resource definitions, the first field should be a string field for the resource name, and it should be called name.

```
message Book {
  // Resource name of the book. It must have the format of "shelves/*/books/*".
  // For example: "shelves/shelf1/books/book2".
  string name = 1;

  // ... other properties
}
```

Q: 为什么不用resource IDs来标识一个resource？
A: 如果用resource ID，我们得用诸如(bucket, object) 或 (user, album, photo)这种元组来标识resource。它有如下问题：

- Developers have to understand and remember such anonymous tuples.
- Passing tuples is generally harder than passing strings.
- Centralized infrastructures, such as logging and access control systems, don't understand specialized tuples.
- Specialized tuples limit API design flexibility, such as providing reusable API interfaces. For example, Long Running Operations can work with many other API interfaces because they use flexible resource names.

Q: Why is the special field called name instead of id?
A: 故意把字段name占用，以强迫开发者在别的地方使用别的字段。
