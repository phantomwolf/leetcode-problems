#  Resource Oriented Design 
## What is a REST API?
A REST API is modeled as collections of individually-addressable resources (the nouns of the API). Resources are referenced with their resource names and manipulated via a small set of methods (also known as verbs or operations).

Standard methods for REST Google APIs (also known as REST methods) are List, Get, Create, Update, and Delete. Custom methods (also known as custom verbs or custom operations) are also available to API designers for functionality that doesn't easily map to one of the standard methods, such as database transactions.

## Design flow

- Determine what types of resources an API provides.
- Determine the relationships between resources.
- Decide the resource name schemes based on types and relationships.
- Decide the resource schemas.
- Attach minimum set of methods to resources.

## Resources
A resource-oriented API is generally modeled as a resource hierarchy, where each node is either a simple resource or a collection resource.

- A collection contains a list of resources of the same type. For example, a user has a collection of contacts.
- A resource has some state and zero or more sub-resources. Each sub-resource can be either a simple resource or a collection resource.

For example, let's see API service: gmail.googleapis.com

- A collection of messages(collection): users/*/messages/*
- A resource representing user settings(simple resource): users/*/settings

## Methods
Standard methods: List, Get, Create, Update, and Delete(CURD plus List).

Custom methods: https://service.name/v1/some/resource/name:customVerb

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

### Relative Resource Name
A URI path (path-noscheme) without the leading "/". It identifies a resource within the API service. For example:

```
shelves/shelf1/books/book2
```


