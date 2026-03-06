INDEX_ORDER_DEFAULT = "default"


def calculate_order(order_method, tensors, path, default):
    if order_method == INDEX_ORDER_DEFAULT:
        return default