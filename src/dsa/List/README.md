# List: API
- Type: `List`

|Function|Parameter|Return type|Description|
|---|---|---|---|
|`init_list`|`List*`|`void`|Init list|
|`is_empty_list`|`List`|`bool`|Check if list if empty|
|`first_list`|`List`|`List_Position`|Get position of first item|
|`end_list`|`List`|`List_Position`|Get position after last item|
|`insert_list`|`List_ElementType`, `List_Position`, `List*`|`void`|Insert `x` to position `p` of list `l`|
|`retreive_list`|`List_Position`, `List`|`List_ElementType`|Get value at position `p` of list `l`|
|`delete_list`|`List_Position`, `List*`|`void`|Delete item at position `p` of list `l`|
|`prev_list`|`List_Position`, `List`|`List_Position`|Get previous position of position `p` of list `l`|
|`next_list`|`List_Position`, `List`|`List_Position`|Get next position of position `p` of list `l`|
|`find_list`|`List_ElementType`, `List`|`List_Position`|Get position of item, return `end_list` if item is not exist|
|`print_list`|`List`|`void`|Print all list|
|`destory_list`|`List`|`void`|Clean up memory after using List|

Choose one of them:
- [fixed_list](./lib/fixed_list.c)
- [linked_list](./lib/linked_list.c)