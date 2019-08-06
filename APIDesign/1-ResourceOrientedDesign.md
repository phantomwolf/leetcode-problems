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
