﻿using System;
using System.ComponentModel.DataAnnotations;
using System.Runtime.Serialization;
using System.Threading.Channels;
namespace Graph_dsa
{
    public class Graph
    {
        private class Node
        {
            public string lable;
            public Node(string lable)
            {
                this.lable = lable;
            }
            public override string ToString()
            {
                return "[" + string.Join(',', lable) + "]";
            }
        }
        Dictionary<string, Node> _nodes = new Dictionary<string, Node>();
        Dictionary<Node, List<Node>> adjaencylist = new Dictionary<Node, List<Node>>(); 
        public void add_node(string data)
        {
            Node node = new Node(data); 
            if(_nodes.TryAdd(data,node))
            {
                _nodes[data] = node;
            }
            adjaencylist.TryAdd(node, new List<Node>());
        }
        public void add_edge(string from,string to)
        {
            var fromnode = _nodes[from];
            if(fromnode == null)
            {
                throw new Exception("from node is not parsent");
            }   
            var tonode = _nodes[to];
            if(tonode == null)
            {
                throw new Exception("to node is noy parsent");
            }
            adjaencylist[fromnode!].Add(tonode!);
        }
        public void print()
        {
            ICollection<Node> nodes = adjaencylist.Keys;
            foreach (var source in adjaencylist.Keys)
            {
                var targets = adjaencylist[source];
                if (targets != null)
                {
                    foreach(var target in targets)
                    {
                        Console.WriteLine(source + " is connected to " + target);
                    }
                }
            }
        }
        public void remove(string data)
        {
            var node= _nodes[data];
            if (node == null) return;
            foreach(var source in adjaencylist.Keys)
            {
                adjaencylist[(source)].Remove(node);
            }
            adjaencylist.Remove(node);
            _nodes.Remove(data);
        }
        public void remove_edge(string from, string to)
        {
            var fromnode= _nodes[from];
            var tonode= _nodes[to];
            if(fromnode == null|| tonode==null)
            {
                return;
            }
            adjaencylist[fromnode!].Remove(tonode!);
        }
    }
   public class Progarm
    {
       static void Main()
        {
            Graph graph = new Graph();
            graph.add_node("A");
            graph.add_node("B");
            graph.add_node("C");
            graph.add_edge("A", "B");
            graph.add_edge("A", "C");
            graph.remove("A");
            graph.add_edge("B", "C");
            graph.print();
        }
    }
}
  